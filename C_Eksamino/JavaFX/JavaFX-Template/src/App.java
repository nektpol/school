import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;


public class App extends Application{
    public void start(Stage primaryStage) 
    {
        primaryStage.setTitle("Anonymous");
        Label label = new Label("");
        label.setText("Hellow, World!");
        Scene scene = new Scene(label, 300, 300);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
    public static void main(String[] args) 
    {
        launch(args);
    }

}
