<?php
	$mysqli = mysqli_connect("localhost", "pi", "", "sensor");
        $interval = 3;
        $sql = "SELECT * FROM THS";
        $result = $mysqli->query($sql);
        $row = $result->fetch_assoc();

	echo "TEMPERATURE :";
	echo $row["value"];
	echo "°C";
	echo "<br>";
	echo "HUMIDITY :";
	echo $row["value2"];
	echo "%";
	echo "<br>";
?>
