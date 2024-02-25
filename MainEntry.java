import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class MainEntry extends JFrame {

    private static final long serialVersionUID = 1L;
    private JTextArea outputTextArea;
    private JComboBox<String> selectSampleBox;
    private JComboBox<String> selectDiagramEditorBox;
    private JComboBox<String> selectLanguageBox;
    private JButton generateCodeButton;
    private JFrame bottomPanelFrame;
    private JPanel bottomPanel;
    private Dimension screenSize;

    public MainEntry() {
        setTitle("Model Driven Development Tool");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(4, 2, 5, 5)); // 6 rows, 2 columns, 5px gaps

        // Get the screen size
        screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        
        JLabel sampleNameLabel = new JLabel("Sample Name");
        selectSampleBox = new JComboBox<>();
        populateSampleBox();

        selectDiagramEditorBox = new JComboBox<>(new String[]{"edu", "com"});

        JButton launchDiagramEditorButton = new JButton("Launch Diagram Editor");
        launchDiagramEditorButton.addActionListener(this::launchDiagramEditor);

        JLabel selectLanguageLabel = new JLabel("Select Language");
        selectLanguageBox = new JComboBox<>(new String[]{"C", "Cpp", "CSharp", "Java"});

        generateCodeButton = new JButton("Generate Code");
        generateCodeButton.addActionListener(e -> generateCode(selectLanguageBox));

        JButton startSimulatorButton = new JButton("Start Simulator");
        startSimulatorButton.addActionListener(e -> startSimulator());

        add(sampleNameLabel);
        add(selectSampleBox);

        add(launchDiagramEditorButton);
        add(selectDiagramEditorBox);

        add(selectLanguageLabel);
        add(selectLanguageBox);
        
        add(generateCodeButton);
        add(startSimulatorButton);

        pack(); // Adjust the frame size to fit the components
        setLocationRelativeTo(null); // Center the frame
        setVisible(true);

        // Initialize the bottom panel frame
        bottomPanelFrame = new JFrame("Output");
        outputTextArea = new JTextArea();
        outputTextArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(outputTextArea);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        bottomPanelFrame.add(scrollPane);
        bottomPanelFrame.setSize(800, 600); // Set the size of the bottom panel frame
        bottomPanelFrame.setLocationRelativeTo(null); // Center the bottom panel frame
        bottomPanelFrame.setVisible(true);
        
        // Initialize the bottom panel
        bottomPanel = new JPanel(new BorderLayout());
        
    }


    private void populateSampleBox() {
        File samplesDir = new File("samples");
        File[] directories = samplesDir.listFiles(File::isDirectory);
        if (directories != null) {
            Arrays.sort(directories);
            for (File dir : directories) {
                selectSampleBox.addItem(dir.getName());
            }
        }
    }

    private void launchDiagramEditor(ActionEvent e) {
        JButton button = (JButton) e.getSource();
        button.setEnabled(false); // Disable the button

        // Launch the target application
        try {
            // Determine the OS and set the appropriate command
            String osName = System.getProperty("os.name").toLowerCase();
            Process process;
            String scriptPath = "./astah-" + selectDiagramEditorBox.getSelectedItem() + "/astah-run.sh";
            String filePath = "./samples/" + selectSampleBox.getSelectedItem() + "/Design.asta";
            if (osName.contains("windows")) {
                process = new ProcessBuilder("D:/cygwin64/bin/bash", "-c", scriptPath + " " + filePath).start();
            } else {
                process = new ProcessBuilder(scriptPath, filePath).start();
            }

            // Monitor the status of the launched application
            new Thread(() -> {
                try {
                    int exitCode = process.waitFor(); // Wait for the process to exit
                    if (exitCode == 0) {
                        // The application exited successfully
                        SwingUtilities.invokeLater(() -> button.setEnabled(true)); // Enable the button
                    }
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }).start();

        } catch (IOException ex) {
            ex.printStackTrace();
            button.setEnabled(true); // Enable the button in case of an error
        }
    }

    private void generateCode(JComboBox<String> selectLanguageBox) {
        JButton button = generateCodeButton;
        button.setEnabled(false); // Disable the button
        outputTextArea.setText(""); // Clear the text area

        // Launch the target application
        try {
            String osName = System.getProperty("os.name").toLowerCase();
            Process process;
            String scriptPath = "./run_C.sh";
            String argument = (String)selectSampleBox.getSelectedItem();
            if (osName.contains("windows")) {
                process = new ProcessBuilder("D:/cygwin64/bin/bash", "-c", scriptPath + " " + argument).start();
            } else {
                process = new ProcessBuilder(scriptPath, argument).start();
            }                    

            // Read and display the error output in a separate thread
            BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            new Thread(() -> {
                try {
                    String errorLine;
                    while ((errorLine = errorReader.readLine()) != null) {
                        final String finalErrorLine = errorLine;
                        SwingUtilities.invokeLater(() -> {
                            outputTextArea.append("Error: " + finalErrorLine + "\n");
                            outputTextArea.setCaretPosition(outputTextArea.getDocument().getLength());
                        });
                    }
                } catch (IOException e0) {
                    e0.printStackTrace();
                }
            }).start();

            // Read and display the output of the process
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            new Thread(() -> {
                try {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        final String finalLine = line;
                        SwingUtilities.invokeLater(() -> {
                            outputTextArea.append(finalLine + "\n"); // Append to the text area
                            outputTextArea.setCaretPosition(outputTextArea.getDocument().getLength()); // Auto-scroll to the bottom
                        });
                    }
                } catch (IOException e0) {
                    e0.printStackTrace();
                }
            }).start();

            // Monitor the status of the launched application
            new Thread(() -> {
                try {
                    int exitCode = process.waitFor(); // Wait for the process to exit
                    if (exitCode == 0) {
                        SwingUtilities.invokeLater(() -> button.setEnabled(true)); // Enable the button
                    }
                } catch (InterruptedException e0) {
                    e0.printStackTrace();
                }
            }).start();

        } catch (IOException e1) {
            e1.printStackTrace();
            button.setEnabled(true); // Enable the button in case of an error
        }
    }
    
    private void startSimulator() {
        // Switch to the ImageLoader view in the bottom panel
        String directoryPath = "./samples/" + selectSampleBox.getSelectedItem() + "/TransImg";
        ImageLoader imageLoader = new ImageLoader(directoryPath);

        // Add the ImageLoader content to the bottom panel
        bottomPanel.removeAll();
        bottomPanel.add(imageLoader.getContentPane());
        bottomPanel.revalidate();
        bottomPanel.repaint();

        // Add the bottom panel to the new frame and make it visible
        bottomPanelFrame.add(bottomPanel);
        bottomPanelFrame.setVisible(true);

        // Calculate the size and position for the xterm console
        int consoleWidth = 80; // 80 characters
        int consoleHeight = 25; // 25 characters
        int xOff = (int)(screenSize.width * 0.66); // Horizontal offset
        int yOff = 0; // Vertical offset (top-right corner)
        
        // Start the external console application
        try {
            String osName = System.getProperty("os.name").toLowerCase();
            ProcessBuilder process;
            String scriptPath = "./start_xterm.sh";
            String geometry = consoleWidth + "x" + consoleHeight + "+" + xOff + "+" + yOff;
            String arguments = (String)selectSampleBox.getSelectedItem();
            if (osName.contains("windows")) {
                process = new ProcessBuilder("D:/cygwin64/bin/bash", "-c", scriptPath + " " + arguments + " " + geometry);
            } else {
                process = new ProcessBuilder(scriptPath, arguments, geometry);
            }
            process.start();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
    
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            MainEntry app = new MainEntry();
            app.setVisible(true);
        });
    }
}
