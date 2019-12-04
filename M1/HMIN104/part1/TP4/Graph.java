package test;

import java.util.ArrayList;

class Pair<L,R> {

    final L left;
    final R right;

    public Pair(L left, R right) {
        this.left = left;
        this.right = right;
    }
    static <L,R> Pair<L,R> of(L left, R right){
        return new Pair<L,R>(left, right);
    }
}

public class Graph{
	private ArrayList<Character> nodes;
	private ArrayList<Pair<Character,Character>> interferenceEdges;
	private ArrayList<Pair<Character,Character>> preferencesEdges;

	public Graph(ArrayList<Character> nds,ArrayList<Pair<Character,Character>> inEdges,ArrayList<Pair<Character,Character>> prefEdges){
		this.nodes=nds;
		this.interferenceEdges=inEdges;
		this.preferencesEdges=prefEdges;
	}

	public ArrayList<Character> getNodes(){
		return this.nodes;
	}

	public ArrayList<Pair<Character,Character>> getInterferenceEdges(){
		return this.interferenceEdges;
	}

	public ArrayList<Pair<Character,Character>> getPreferencesEdges(){
		return this.preferencesEdges;
	}

	public void setNodes(ArrayList<Character> nds){
		this.nodes=nds;
	}

	public void setInterferenceEdges(ArrayList<Pair<Character,Character>> inEdges){
		this.interferenceEdges=inEdges;
	}

	public void setPreferencesEdges(ArrayList<Pair<Character,Character>> prefEdges){
		this.preferencesEdges=prefEdges;
	}


	public void printNodes(){
		System.out.println("Les sommets du graphe : \n");
			for(Character c: nodes)	
				System.out.println(c+"\t");
		System.out.println("\n");
	}

	public void printInterferenceEdges(){
		System.out.println("Les arêtes d'interference du graphe : \n");
			for(Pair<Character,Character> c: interferenceEdges)	
				System.out.println("("+c.left+","+c.right+")\t");
		System.out.println("\n");
	}

	public void printPreferencesEdges(){
		System.out.println("Les arêtes de preference du graphe : \n");
		for(Pair<Character,Character> c: preferencesEdges)	
				System.out.println("("+c.left+","+c.right+")\t");
		System.out.println("\n");
	}

}