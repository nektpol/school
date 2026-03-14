<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Στοιχεία Φοιτητή</title>
</head>
<body>

<h2>Φόρμα Φοιτητή</h2>

<form method="post">

    Όνομα:<br>
    <input type="text" name="name" required><br><br>

    Επώνυμο:<br>
    <input type="text" name="surname" required><br><br>

    Ηλικία:<br>
    <input type="number" name="age" required><br><br>

    Μάθημα επιλογής:<br>
    <select name="course">
        <option value="Προγραμματισμός">Προγραμματισμός</option>
        <option value="Βάσεις Δεδομένων">Βάσεις Δεδομένων</option>
        <option value="Δίκτυα">Δίκτυα</option>
    </select>

    <br><br>

    <h3>Βαθμοί Μαθημάτων</h3>

    Προγραμματισμός:
    <input type="number" name="grade1" min="0" max="10" required>
    <br><br>

    Βάσεις Δεδομένων:
    <input type="number" name="grade2" min="0" max="10" required>
    <br><br>

    Δομές Δεδομένων:
    <input type="number" name="grade3" min="0" max="10" required>
    <br><br>

    Δίκτυα Υπολογιστών:
    <input type="number" name="grade4" min="0" max="10" required>
    <br><br>

    Λειτουργικά Συστήματα:
    <input type="number" name="grade5" min="0" max="10" required>
    <br><br>

    <input type="submit" value="Υποβολή">

</form>

<?php

if($_SERVER["REQUEST_METHOD"] == "POST")
{
    $name = $_POST["name"];
    $surname = $_POST["surname"];
    $age = $_POST["age"];
    $course = $_POST["course"];

    $grades = [
        $_POST["grade1"],
        $_POST["grade2"],
        $_POST["grade3"],
        $_POST["grade4"],
        $_POST["grade5"]
    ];

    echo "<h3>Ο φοιτητής $name $surname, ηλικίας $age, επέλεξε το μάθημα $course.</h3>";

    $sum = 0;

    foreach($grades as $grade)
    {
        $sum += $grade;
    }

    $average = $sum / count($grades);

    echo "Μέσος Όρος: " . $average . "<br>";

    if($average >= 5)
    {
        echo "Ο φοιτητής πέρασε το μάθημα.";
    }
    else
    {
        echo "Ο φοιτητής κόπηκε.";
    }
}

?>


</body>
</html>