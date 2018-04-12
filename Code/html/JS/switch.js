function switch(){

	if(document.getElementById("toggle--neon").checked){
		$.ajax({
			url:"turnOn.php",
			type:"POST",
			success:function(result){
				alert(result);
			}
		});
	}
	else{
		 $.ajax({
                        url:"turnOff.php",
                        type:"POST",
                        success:function(result){
                                alert(result);
                        }
                });

        }
}
