<!DOCTYPE html>
<html>
        <head>
                <meta charset="UTF-8">
                <script src="JS/jquery.min.js"></script>
		<script src="JS/vue.min.js"></script>
                <link rel="stylesheet" type="text/css" media="all" href="CSS/font.css">
	</head>

	<script>
                $(document).ready(function(){

                        setInterval(function(){

                                $("#data").load("th.php");

                        },1000);

                });


        </script>

	<div id="digital">
		<p class="data">
			<h1><div id="data"></div></h1>
		</p>
	</div>




        <div id="clock">
         <p class="date">{{ date }}</p>
         <p class="time">{{ time }}</p>
        </div>
	<script src="JS/clock.js"></script>

        </body>
</html>




