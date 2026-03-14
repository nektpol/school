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
    <input type="submit" value="Υποβολή">

</form>

<?php

if($_SERVER["REQUEST_METHOD"] == "POST")
{
    $name = $_POST["name"];
    $surname = $_POST["surname"];
    $age = $_POST["age"];
    $course = $_POST["course"];

    echo "<h3>Ο φοιτητής $name $surname, ηλικίας $age, επέλεξε το μάθημα $course.</h3>";
}

?>

<?php

$grades = [7, 6, 8, 5, 4];   // 5 βαθμοί

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

?>

</body>
</html>