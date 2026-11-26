import java.util.ArrayList;
import java.util.Random;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import net.objecthunter.exp4j.ExpressionBuilder;



public class Controller {

    @FXML
    private Button btnPlus;

    @FXML
    private Button btnMultiply;

    @FXML
    private Button btnMinus;

    @FXML
    private Label equationLabel;

    @FXML
    private Label resultLabel;

    private ArrayList<Integer> numbers = new ArrayList<>();
    private ArrayList<String> operators = new ArrayList<>();

    private int difficulty = 2;
    private Random random = new Random();

    public void initialize() {
        generateNewQuestion();
    }

    @FXML
    private void generateNewQuestion() {
        
        for (int i = 0; i < difficulty; i++) {
            numbers.add(random.nextInt(10) + 1);
        }

        String[] ops = {"+", "-", "*"};
        for (int i = 0; i < difficulty - 1; i++) {
            operators.add(ops[random.nextInt(ops.length)]);
        }

        String equationString = "";
        for (int i = 0; i < difficulty; i++) {
            equationString += numbers.get(i);
            if (i < operators.size()) {
                equationString +=operators.get(i);
            }
        }

        double result = new ExpressionBuilder(equationString)
                .build()
                .evaluate();

        int finalResult = (int) Math.ceil(result);

        String displayEquation = "";
        for (int i = 0; i < equationString.length(); i++) {
            char c = equationString.charAt(i);
            if (Character.isDigit(c)) {
                displayEquation += c;
            } else {
                displayEquation += "_";
            }
        }
        displayEquation += "=" + finalResult;
        equationLabel.setText(displayEquation);
    }

    @FXML
    private void checkAnswer() {

    }

    @FXML
    private void HandleOperationPlus() {

    }

    @FXML
    private void HandleOperationMinus() {

    }

    @FXML
    private void HandleOperationMultiply() {

    }

    @FXML
    private void HandleBackspace() {

    }

}