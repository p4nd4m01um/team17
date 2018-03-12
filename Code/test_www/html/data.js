$(function()
{
	var datatext = $("[data]");
	
	setInterval(function()
	{
		$.post("thdata.php", {type : "dataupdate"}, function(data)
		{
			datatext.html("data:<?php echo $row["passwd"]; ?></p>")
		});
	}, 1000);
});
