package dico;

public class prog {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("OrderedDictionary");
		OrderedDictionary dico_O = new OrderedDictionary(3);
		dico_O.put("Terki","Adel").put("Yasmine","Khadra").put("Kateb","Yacine");	
		System.out.println(dico_O.get("Terki"));
		System.out.println(dico_O.isEmpty());
		System.out.println(dico_O.containsKey("Yasmine"));
		
		System.out.println("FastDictionary");
		FastDictionary dico_F = new FastDictionary(16);
		dico_F.put("Corbillard","Anne-Marie").put("Ramirez","Erica").put("Canchez","Olenka").put("Bujon","Julie");	
		dico_F.put("Olighen","Anyeshka").put("hoërnkuv","Geva").put("Kerd","Dalila").put("Poireau","Julie");
		dico_F.put("Fisher","Lauren").put("Dupont","Marie").put("Amokrane","Numidia").put("Boudrahem","Shanna");
		dico_F.put("Remon","Asmaé").put("Villas","Lorie").put("Cheikh","Yousra").put("Pubon","Alix");
		System.out.println(dico_F.get("Ramirez"));
		System.out.println(dico_F.isEmpty());
		System.out.println(dico_F.containsKey("Remon"));
		System.out.println(dico_F.size());
		
		System.out.println("SortedDictionary");
		SortedDictionary dico_S = new SortedDictionary(10);
		dico_S.put("Zer","To").put("Yik","Lahar").put("Ber","Pori").put("Ada","Lovelace");
		
		
	}

}
