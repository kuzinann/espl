
window.onload = function () {
      document.getElementById("firstName").onkeydown= function(pressed){
	var KEY_CODE_0 = 48
	var KEY_CODE_9 = 57
	//returns whether keep 
	if(pressed.keyCode<=57 && pressed.keyCode>=48){
	  return false;
	}else{
	  return true;
	} 
	
      }
}