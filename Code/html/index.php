<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<script src="http://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js"></script>
	<script>
		$(document).ready(function(){

			setInterval(function(){

				$("#th_data").load("th.php");

			},500);

		});


	</script>
	</head>

	<body>
	<div id="th_data">

	</div>
	<button> START </button>
	</body>
</html>
