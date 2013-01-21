
window.onload = function () {
      
      document.getElementById("firstName").onkeydown= function(pressed){
	
	 if(document.getElementById("sub").disabled == true){
	   document.getElementById("sub").disabled = false;
	 } 
	 
	var KEY_CODE_0 = 48
	var KEY_CODE_9 = 57
	
	showHint(this.value);
	
	if(pressed.keyCode<=57 && pressed.keyCode>=48){
	  return false;
	}else{
	  
	  return true;
	} 
	
	
      }
      document.getElementById("pass").onkeydown= function(pressed){
	 
	 if(document.getElementById("sub").disabled == true){
	   document.getElementById("sub").disabled = false;
	 }  

	 var textInField = this.value;
	 var firstChar = textInField.charAt(0);
	  
	 if(textInField.length >0){
	  if (/[a-zA-Z]/.test(firstChar)) {
	      return true;
	  }    
	  
	  return false;
	 }   

      }  
      
      document.getElementById("sub").onmousedown= function(pressed){
	
	 if((document.getElementById("pass").value.length <5) || (document.getElementById("firstName").value.length <1)){
	  document.getElementById("sub").disabled = true;
	 }
	

      }  
      
      document.getElementById("hidding").onmouseover= function(pressed){
	  this.style.visibility = "hidden";
	
      }	
      
}

//////Ajax code

function showHint(str){
  var xmlhttp;
  if (str.length==0){
    document.getElementById("txtHint").innerHTML="";
  return;
  }
  if (window.XMLHttpRequest){// IE7+,Firefox,Chrome,Opera, Safari
    xmlhttp=new XMLHttpRequest();
  }
  else{// code for IE6, IE5
    xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }
  xmlhttp.onreadystatechange=function(){
  if (xmlhttp.readyState==4 &&xmlhttp.status==200){
    document.getElementById("txtHint").innerHTML=xmlhttp.responseText;
  }
  
  }
  
  xmlhttp.open("GET","http://www.cs.bgu.ac.il/~kuzinann/suggest.php",true);
  xmlhttp.send(str);
}
