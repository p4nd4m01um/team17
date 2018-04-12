function foo(){
		if(document.getElementById("toggle--neon").checked){
			alert("checkbox is checked");
		}
		else{
			alert("checkbox is unchecked");
                }
        }
function disable_start(){
                        document.getElementById("start").disabled=true;
                        document.getElementById("stop").disabled=false;
        }
function disable_stop(){
                          document.getElementById("start").disabled=false;
                        document.getElementById("stop").disabled=true;
        }

