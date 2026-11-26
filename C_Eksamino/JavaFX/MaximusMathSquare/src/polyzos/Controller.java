package polyzos;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
/** Controller and game model for the 3x3 sliding puzzle. */
public class Controller {

    @FXML private Label counterLabel;
    @FXML private Label messageLabel;

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

    private static final int SIZE = 3;
    private static final int SHUFFLE_MOVES = 80;
    private final int[][] board = new int[SIZE][SIZE];
    private final Map<Integer, Button> buttonMap = new HashMap<>();
    private final Random random = new Random();
    private int emptyRow;
    private int emptyCol;
    private int moves;
    private boolean gameFinished;

    @FXML
    public void initialize() {
        buttonMap.put(1, btnOne);
        buttonMap.put(2, btnTwo);
        buttonMap.put(3, btnThree);
        buttonMap.put(4, btnFour);
        buttonMap.put(5, btnFive);
        buttonMap.put(6, btnSix);
        buttonMap.put(7, btnSeven);
        buttonMap.put(8, btnEight);

        startNewGame();
    }

    @FXML
    private void onButtonClick(ActionEvent event) {
        if (gameFinished) {
            return;
        }
        Button clickedButton = (Button) event.getSource();
        int value = Integer.parseInt(clickedButton.getText());
        int[] position = findValue(value);
        if (!isAdjacent(position[0], position[1])) return;

        board[emptyRow][emptyCol] = value;
        board[position[0]][position[1]] = 0;
        emptyRow = position[0];
        emptyCol = position[1];
        moves++;
        renderBoard();
        counterLabel.setText(Integer.toString(moves));

        if (isSolved()) {
            gameFinished = true;
            setTilesDisabled(true);
            messageLabel.setText("Συγχαρητήρια! Το παζλ λύθηκε σε " + moves + " κινήσεις!");
        }
    }

    private boolean isSolved() {
        int expected = 1;
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                int required = expected <= 8 ? expected++ : 0;
                if (board[row][col] != required) return false;
            }
        }
        return true;
    }

    @FXML
    private void shuffleButtons() {
        startNewGame();
    }

    private void startNewGame() {
        fillSolvedBoard();
        int previousEmptyRow = -1;
        int previousEmptyCol = -1;
        for (int i = 0; i < SHUFFLE_MOVES; i++) {
            List<int[]> neighbors = getNeighbors(emptyRow, emptyCol);
            if (neighbors.size() > 1) {
                final int oldRow = previousEmptyRow;
                final int oldCol = previousEmptyCol;
                neighbors.removeIf(cell -> cell[0] == oldRow && cell[1] == oldCol);
            }
            int[] next = neighbors.get(random.nextInt(neighbors.size()));
            previousEmptyRow = emptyRow;
            previousEmptyCol = emptyCol;
            swapWithEmpty(next[0], next[1]);
        }
        if (isSolved()) swapWithEmpty(emptyRow, emptyCol == 0 ? 1 : emptyCol - 1);
        moves = 0;
        gameFinished = false;
        counterLabel.setText("0");
        messageLabel.setText("Μετακίνησε τα πλακίδια στη σωστή σειρά.");
        setTilesDisabled(false);
        renderBoard();
    }

    private void fillSolvedBoard() {
        int value = 1;
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) board[row][col] = value <= 8 ? value++ : 0;
        }
        emptyRow = SIZE - 1;
        emptyCol = SIZE - 1;
    }

    private void renderBoard() {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                int value = board[row][col];
                if (value != 0) {
                    GridPane.setRowIndex(buttonMap.get(value), row);
                    GridPane.setColumnIndex(buttonMap.get(value), col);
                }
            }
        }
    }

    private int[] findValue(int value) {
        for (int row = 0; row < SIZE; row++) for (int col = 0; col < SIZE; col++)
            if (board[row][col] == value) return new int[] { row, col };
        throw new IllegalArgumentException("Unknown tile: " + value);
    }

    private boolean isAdjacent(int row, int col) {
        return Math.abs(row - emptyRow) + Math.abs(col - emptyCol) == 1;
    }

    private void swapWithEmpty(int row, int col) {
        board[emptyRow][emptyCol] = board[row][col];
        board[row][col] = 0;
        emptyRow = row;
        emptyCol = col;
    }

    private List<int[]> getNeighbors(int row, int col) {
        List<int[]> neighbors = new ArrayList<>();
        if (row > 0) neighbors.add(new int[] { row - 1, col });
        if (row < SIZE - 1) neighbors.add(new int[] { row + 1, col });
        if (col > 0) neighbors.add(new int[] { row, col - 1 });
        if (col < SIZE - 1) neighbors.add(new int[] { row, col + 1 });
        Collections.shuffle(neighbors, random);
        return neighbors;
    }

    private void setTilesDisabled(boolean disabled) {
        buttonMap.values().forEach(button -> button.setDisable(disabled));
    }
}
