/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


var divDOM=document.createElement("div");
divDOM.style.color = "black";
divDOM.style.backgroundColor = "yellow";
divDOM.style.fontSize="24px";
document.body.appendChild(divDOM);



function analyseDOM(noeud,indent)
{	
	var node = document.createTextNode('');
	var type = 'NiElemNiAttribNiText';
	if (noeud == null  || noeud == divDOM) return;
	switch (noeud.nodeType)
	{
		case 1 : type='Element';
			break;
			
		case 2 : type='Attribute';
			break;
			
		case 3 : type='Text';
			break;
			
		case 9 : type='Document';
			break;
	}
	
	
	
	for(var i=0;i<indent;i++)
	{
		node.appendData("___  ");
	}
	
	
	node.appendData(type+"-"+noeud.nodeName+" "+(noeud.nodeValue?'"'+noeud.nodeValue+'"':"")+" Enfants : "+noeud.childNodes.length);
	
	divDOM.appendChild(node);
	var sautDeLigne = document.createElement("br");
	divDOM.appendChild(sautDeLigne);
	
	for(var enfant=0;enfant < noeud.childNodes.length;enfant++)
	{		
			analyseDOM(noeud.childNodes.item(enfant),indent++);
	}
}


analyseDOM(document,0);








