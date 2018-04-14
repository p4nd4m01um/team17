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


	<div class="toggle toggle--neon">
		<input type="checkbox" id="toggle--neon" class="toggle--checkbox" onchange="ppowerr();">
		<label class="toggle--btn" for="toggle--neon" data-label-on="on"  data-label-off="off"></label>
	</div>
	<script>
		function ppowerr(){

			if(document.getElementById("toggle--neon").checked){
				$.ajax({
					url:"turnOn.php",
					type:"POST",
					success:function(result){
						alert("checked");
					}
				});
			}
			else{
				 $.ajax({
                     			   url:"turnOff.php",
              			           type:"POST",
                     			   success:function(result){
                             			   alert("unchecked");
                       			   }
               			 });

        		}
		}
	</script>
        </body>
</html>











