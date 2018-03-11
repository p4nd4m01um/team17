<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js"></script>
	<script>
		$(document).ready(function(){
			
			setInterval(function(){
				
				$("#data").load("thdata.php", {
					
				});
			},1000);
		});
	</script>

	</head>

	<body>
	<div id="data">
		<?php include("thdata.php");?>
	</div>

	</body>
</html>
		

