<!DOCTYPE html>
<html>
        <head>
                <meta charset="UTF-8">
                <script src="JS/jquery.min.js"></script>
		<script src="JS/vue.min.js"></script>
		<link rel="stylesheet" tpye="text/css" media="all" href="CSS/switch.css">
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


	<div class="toggle toggle--neon">
		<input type="checkbox" id="toggle--neon" class="toggle--checkbox" onclick="switch();">
		<label class="toggle--btn" for="toggle--neon" data-label-on="on"  data-label-off="off"></label>
	</div>
	<script src="JS/switch.js"></script>

        </body>
</html>











