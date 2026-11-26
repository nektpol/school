package polyzos;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("MaximusMathSquare.fxml"));
        primaryStage.setTitle("MaximusMathSquare");
        primaryStage.setScene(new Scene(root, 460, 560));
        primaryStage.setMinWidth(460);
        primaryStage.setMinHeight(560);
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
