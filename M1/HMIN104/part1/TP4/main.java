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


public static void main(String args[]){
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
}

}
