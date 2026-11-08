package maximusmathsquare;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.HashMap;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.geometry.Point2D;

public class Controller {

    @FXML
    private Label counterLabel ;

    @FXML
    private Button btnOne;

    @FXML
    private Button btnTwo;

    @FXML
    private Button btnThree;

    @FXML
    private Button btnFour;

    @FXML
    private Button btnFive;

    @FXML
    private Button btnSix;

    @FXML
    private Button btnSeven;

    @FXML
    private Button btnEight;

    @FXML
    private Button btnShuffle;

    private int clickCount = 0;

    private int[][] numbers = new int[3][3];

    private Map<Integer, Button> buttonMap = new HashMap<>();

    private Point2D emptyCell;

    @FXML
    public void initialize() {
        // Αρχικοποίηση αν χρειάζεται
        buttonMap.put(1, btnOne);
        buttonMap.put(2, btnTwo);
        buttonMap.put(3, btnThree);
        buttonMap.put(4, btnFour);
        buttonMap.put(5, btnFive);
        buttonMap.put(6, btnSix);
        buttonMap.put(7, btnSeven);
        buttonMap.put(8, btnEight);

        shuffleButtons();
    }

    @FXML
    private void onButtonClick(ActionEvent event) {
        Button clickedButton = (Button) event.getSource();

        int currentCol = getColumn(clickedButton);
        int currentRow = getRow(clickedButton);

        if (!isNeighborWithEmptyCell(new Point2D(currentCol, currentRow))) {
            return;
        }

        int targetCol = (int) emptyCell.getX();
        int targetRow = (int) emptyCell.getY();

        GridPane.setColumnIndex(clickedButton, targetCol);
        GridPane.setRowIndex(clickedButton, targetRow);

        // Ενημέρωση της θέσης του κενού κελιού
        emptyCell = new Point2D(currentCol, currentRow);

        clickCount++;
        counterLabel.setText(String.valueOf(clickCount));

        if (isSolved()) {
            // Εδώ μπορείτε να προσθέσετε κώδικα για να χειριστείτε την επίλυση του παζλ
            System.out.println("Puzzle solved!");
        }
    }

    private int getColumn(Button button) {
        Integer col = GridPane.getColumnIndex(button);
        return (col == null) ? 0 : col;
    }

    private int getRow(Button button) {
        Integer row = GridPane.getRowIndex(button);
        return (row == null) ? 0 : row;
    }

    private boolean isNeighborWithEmptyCell(Point2D cell) {
        int col = (int) cell.getX();
        int row = (int) cell.getY();

        int emptyCol = (int) emptyCell.getX();
        int emptyRow = (int) emptyCell.getY();

        return (Math.abs(col - emptyCol) == 1 && row == emptyRow) ||
               (Math.abs(row - emptyRow) == 1 && col == emptyCol);
    }

    
    private boolean isSolved(){
        return getColumn(btnOne) == 0 && getRow(btnOne) == 0 &&
               getColumn(btnTwo) == 1 && getRow(btnTwo) == 0 &&
               getColumn(btnThree) == 2 && getRow(btnThree) == 0 &&
               getColumn(btnFour) == 0 && getRow(btnFour) == 1 &&
               getColumn(btnFive) == 1 && getRow(btnFive) == 1 &&
               getColumn(btnSix) == 2 && getRow(btnSix) == 1 &&
               getColumn(btnSeven) == 0 && getRow(btnSeven) == 2 &&
               getColumn(btnEight) == 1 && getRow(btnEight) == 2;
    }

    @FXML
    private void shuffleButtons() {
        List<Integer> values = new ArrayList<>();

        for (int i = 0; i <= 8; i++) {
            values.add(i);
        }

        Collections.shuffle(values);

        int index = 0;

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                numbers[row][col] = values.get(index);
                if (numbers[row][col] != 0) {
                    GridPane.setColumnIndex(buttonMap.get(numbers[row][col]), col);
                    GridPane.setRowIndex(buttonMap.get(numbers[row][col]), row);
                }
                else {
                    emptyCell = new Point2D(col, row);
                }
                index++;
            }
        }

        clickCount = 0;
        counterLabel.setText(String.valueOf(clickCount));
    }
}