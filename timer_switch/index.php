#
<!DOCTYPE html>
<html>
        <head>
                <meta charset="UTF-8">
                <script src="http://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js"></script>
		<script src="https://cdnjs.cloudflare.com/ajax/libs/vue/2.3.4/vue.min.js"></script>
                <link rel="stylesheet" type="text/css" media="all" href="font.css">
		<link rel="stylesheet" tpye="text/css" media="all" href="onoff.css">
	</head>

	<script>
                $(document).ready(function(){

                        setInterval(function(){

                                $("#data").load("thdata.php");

                        },500)

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
	<script src="clock.js"></script>






		<div class="toggle toggle--neon">
			<input type="checkbox" id="toggle--neon" class="toggle--checkbox" onchange="foo();">
			<label class="toggle--btn" for="toggle--neon" data-label-on="on"  data-label-off="off"></label>
		</div>
		<script src="dis.js"></script>
        </body>
</html>



