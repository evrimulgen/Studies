
import java.io.IOException;
import java.time.Instant;
import java.util.Arrays;
import java.util.Iterator;
import java.util.logging.FileHandler;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class GroupBy {
	private static final String INPUT_PATH = "input-groupBy/";
	private static final String OUTPUT_PATH = "output/groupBy-";
	private static final Logger LOG = Logger.getLogger(GroupBy.class.getName());

	static {
		System.setProperty("java.util.logging.SimpleFormatter.format", "%5$s%n%6$s");

		try {
			FileHandler fh = new FileHandler("out.log");
			fh.setFormatter(new SimpleFormatter());
			LOG.addHandler(fh);
		} catch (SecurityException | IOException e) {
			System.exit(1);
		}
	}

	public static class Map extends Mapper<LongWritable, Text, Text, DoubleWritable> {
		private final static String emptyWords[] = { "" };
		
		@Override
		public void map(LongWritable key, Text value, Context context) {
			// TODO: à compléter
			
			String line = value.toString();

			//Une méthode pour créer des messages de log
			//LOG.info("MESSAGE INFO");
		
			String[] words = line.split(",");
			
			
			if (Arrays.equals(words, emptyWords))
				return;
			
			if ((words[words.length-1]).equals("Profit") )
				return;
			
			//exo 3
			//LOG.info("Client_ID : "+words[5]+"  profit  : "+words[words.length-1]);
			//exo 4 par date et state
			//LOG.info("order date : "+words[2]+"  state : "+words[10]+"  profit  : "+words[words.length-1]);
			//exo 4 par date et catégorie
			//LOG.info("order date : "+words[2]+"   category : "+words[14]+"  profit  : "+words[words.length-1]);
			//exo 4 les commandes  
			LOG.info("order_ID : "+words[1]+"   product_ID : "+words[13]+"  quantity  : "+words[18]);
			//exo 3 & exo 4(ventes)
			//DoubleWritable myDouble=new DoubleWritable(Double.valueOf(words[words.length-1]));
			//exo 4 commandes (exemplaire tot)
			//DoubleWritable myDouble=new DoubleWritable(Double.valueOf(words[18]));
			//exo 4 commandes (produits Diff tot)
			DoubleWritable myDouble=new DoubleWritable(1);
			try {
				//exo3
				//context.write(new Text(words[5]),myDouble);
				/*exo4 totaux des ventes par Date et state
				context.write(new Text(words[2]+"  "+words[10]),myDouble);
				*/
			
				/*exo4 totaux des ventes par Date et catégorie
				context.write(new Text(words[2]+"  "+words[14]),myDouble);
				*/
				//exo4 totaux exemplaires par  commande
				//context.write(new Text(words[1]),myDouble);
				//exo4 totaux produits diff par  commande
				context.write(new Text(words[1]),myDouble);
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}

	public static class Reduce extends Reducer<Text, DoubleWritable, Text, DoubleWritable> {

		@Override
		public void reduce(Text key, Iterable<DoubleWritable> values, Context context)
				throws IOException, InterruptedException {
			// TODO: à compléter
			int sum = 0;

			System.out.println(context);
			for (DoubleWritable val : values)
				sum += val.get();
				context.write(key, new DoubleWritable(sum));
			
		}
	}

	

	/*
	public static class Map extends Mapper<LongWritable, Text, Text, Text> {
		private final static String emptyWords[] = { "" };
		
		@Override
		public void map(LongWritable key, Text value, Context context) {
			// TODO: à compléter
			
			String line = value.toString();

			//Une méthode pour créer des messages de log
			//LOG.info("MESSAGE INFO");
		
			String[] words = line.split(",");
			
			
			if (Arrays.equals(words, emptyWords))
				return;
			
			if ((words[words.length-1]).equals("Profit") )
				return;
			
			LOG.info("order_ID : "+words[1]+"   product_ID : "+words[13]+"  quantity  : "+words[18]);
			Text text=new Text(words[13]);
			try {
				context.write(new Text(words[1]),text);
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}

	public static class Reduce extends Reducer<Text, Text, Text, Text> {

		@Override
		public void reduce(Text key, Iterable<Text> values, Context context)
				throws IOException, InterruptedException {
			// TODO: à compléter
			Double sumProduitsDiff =0.0;
			Iterator<Text> rech=values.iterator();
			String product=rech.next().toString();
			
			System.out.println(context);
			for (Text val : values) {
				String line = val.toString();
				if(!rech.equals(line))
					sumProduitsDiff++;				
			}
			
			Text res=new Text(""+sumProduitsDiff);	
				context.write(key, res);
			
		}
	}
*/
	public static void main(String[] args) throws Exception {
		Configuration conf = new Configuration();

		Job job = new Job(conf, "GroupBy");

		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);

		job.setMapperClass(Map.class);
		job.setReducerClass(Reduce.class);

		job.setOutputValueClass(DoubleWritable.class); 

		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		FileInputFormat.addInputPath(job, new Path(INPUT_PATH));
		FileOutputFormat.setOutputPath(job, new Path(OUTPUT_PATH + Instant.now().getEpochSecond()));

		job.waitForCompletion(true);
	}
}