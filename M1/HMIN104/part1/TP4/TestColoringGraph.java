package test;

import java.io.*; 
import java.util.*; 



public class TestColoringGraph{
	
	public static ArrayList<Pair<Character,Integer>> colorinGraph(Graph g,int k){
		ArrayList<Pair<Character,Integer>> affectColors;
		Stack<Character> toColor;
		Random rand;	
		//initialization
		affectColors = new ArrayList<Pair<Character,Integer>>();
		toColor = new Stack<Character>();
		rand = new Random();
		for(Character currentNode: g.getNodes()){
			int nbOccurences=0;
			for(Pair<Character,Character> edge : g.getInterferenceEdges()){
				if(edge.left.equals(currentNode) || edge.right.equals(currentNode))
						nbOccurences++;
			}
			if(nbOccurences <= k){
				toColor.push(currentNode);
			}	
		}
		while(!toColor.empty()){
			Character colorNode=toColor.pop();
			if(affectColors.isEmpty()){
				affectColors.add(new Pair(colorNode,rand.nextInt(k)));
			}else{
				Pair<Character,Integer> compareColor=affectColors.get(affectColors.size()-1);
				int theColor;
				do{
					theColor=rand.nextInt(k);
				}while(theColor == k);
				affectColors.add(new Pair(colorNode,theColor));
			}
		}
		return affectColors;
	}

	public static void drawColoredGraph(Graph g,ArrayList<Pair<Character,Integer>> colors) throws FileNotFoundException{
		HashMap<Integer,String> existingColors=new HashMap<Integer,String>();
		existingColors.put(0,"blue");
		existingColors.put(1,"yellow");
		existingColors.put(2,"red");
		existingColors.put(3,"white");
		existingColors.put(4,"green");
		existingColors.put(5,"magenta");
		PrintWriter writer=null;
		/*try{
			File file = new File("/auto_home/mterki/MASTER/M1/S1/HMIN104/TP-TP/TP4/coloredGraph.dot");
			file.getParentFile().mkdirs();
			writer = new PrintWriter(file);
		}catch(FileNotFoundException E){
			System.out.println("fichier introuvable ! ");
		}*/
		writer = new PrintWriter(new File("/auto_home/mterki/MASTER/M1/S1/HMIN104/TP-TP/TP4/coloredGraph.dot"));  
		writer.write("graph myGraph{ \n");
		for(Pair<Character,Integer> nd : colors){
			writer.write(nd.left+"[style=\"filled\" fillcolor ="+existingColors.get(nd.right)+"] \n");
		}
		for(Pair<Character,Character> edge: g.getInterferenceEdges())	
			writer.write(edge.left+"--"+edge.right+"\n");
		for(Pair<Character,Character> edge: g.getPreferencesEdges())	
			writer.write(edge.left+"--"+edge.right+" [style=dotted]\n");
		writer.write("}");
		writer.close();
	}

public static void main(String args[]) {
	//declaration and initialization
	ArrayList<Character> nodes=new ArrayList<Character>();
	ArrayList<Pair<Character,Character>> interferenceEdges=new ArrayList<Pair<Character,Character>>();
	ArrayList<Pair<Character,Character>> preferencesEdges = new ArrayList<Pair<Character,Character>>();

	nodes.add('x');
	nodes.add('y');
	nodes.add('u');
	nodes.add('v');
	nodes.add('t');
	nodes.add('z');

	interferenceEdges.add(new Pair<Character,Character>('x','y'));
	interferenceEdges.add(new Pair<Character,Character>('x','u'));
	interferenceEdges.add(new Pair<Character,Character>('x','v'));
	interferenceEdges.add(new Pair<Character,Character>('u','y'));
	interferenceEdges.add(new Pair<Character,Character>('v','z'));
	interferenceEdges.add(new Pair<Character,Character>('y','t'));

	preferencesEdges.add(new Pair<Character,Character>('u','t'));
	Graph myGraph = new Graph(nodes,interferenceEdges,preferencesEdges);
	myGraph.printNodes();
	myGraph.printInterferenceEdges();
	myGraph.printPreferencesEdges();

	ArrayList<Pair<Character,Integer>> result = colorinGraph(myGraph,3);

	for(Pair<Character,Integer> nodeColor: result)	
				System.out.println("("+nodeColor.left+","+nodeColor.right+")\t");
		System.out.println("\n");
		
	try {
		drawColoredGraph(myGraph,result);
	} catch (FileNotFoundException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}	
}

}
