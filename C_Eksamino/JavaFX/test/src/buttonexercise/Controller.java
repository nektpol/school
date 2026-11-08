package buttonexercise;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class Controller {

    @FXML
    private Label label;

    @FXML
    private Button plusButton;
    @FXML
    private Button exitButton;
    @FXML
    private Button minusButton;
    @FXML
    private Button resetButton;

    private int clickCount = 0;

    public void initialize() {
        String javaVersion = System.getProperty("java.version");
        String javafxVersion = System.getProperty("javafx.version");
        label.setText("Hello, JavaFX " + javafxVersion + "\nRunning on Java " + javaVersion + ".");
    }

    @FXML
    private void onPlusButtonClick() {
        clickCount++;
        label.setText("Το κουμπί πατήθηκε " + clickCount + " φορά/φορές!");
    }

    @FXML
    private void onMinusButtonClick() {
        clickCount--;
        label.setText("Το κουμπί πατήθηκε " + clickCount + " φορά/φορές!");
    }

    @FXML
    private void onExitButtonClick() {
        System.exit(0);
    }

    @FXML
    private void onResetButtonClick() {
        clickCount = 0;
        label.setText("Το κουμπί επαναφέρθηκε!");
    }
}
