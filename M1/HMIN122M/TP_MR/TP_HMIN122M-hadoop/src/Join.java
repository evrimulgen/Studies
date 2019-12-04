import java.io.IOException;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Arrays;
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
import org.apache.hadoop.mapreduce.Reducer.Context;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.mapreduce.lib.input.MultipleInputs;

public class Join {
	private static final String OUTPUT_PATH = "output/join-";
	private static final Logger LOG = Logger.getLogger(Join.class.getName());

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

	public static class CustomerMapper extends Mapper<LongWritable, Text, Text,Text> {
		private final static String emptyWords[] = { "" };
		
		@Override
		public void map(LongWritable key, Text value, Context context) {
			// TODO: à compléter
			
			String line = value.toString();

			//Une méthode pour créer des messages de log
			//LOG.info("MESSAGE INFO");
		
			String[] words = line.split("\\|");
			
			
			if (Arrays.equals(words, emptyWords))
				return;
			
			LOG.info("CUSTOMER.custKey : "+words[0]+"\tCUSTOMER.name : "+words[1]);
	
			try {
				context.write(new Text(words[0]),new Text(words[0]+","+words[1]));
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}
	
	public static class OrderMapper extends Mapper<LongWritable, Text, Text,Text> {
		private final static String emptyWords[] = { "" };
		
		@Override
		public void map(LongWritable key, Text value, Context context) {
			// TODO: à compléter
			
			String line = value.toString();

			//Une méthode pour créer des messages de log
			//LOG.info("MESSAGE INFO");
		
			String[] words = line.split("\\|");
			
			
			if (Arrays.equals(words, emptyWords))
				return;
			
			LOG.info("ORDRE.custKey: "+words[1]+"\tORDER.comment: "+words[8]);
	
			try {
				context.write(new Text(words[1]),new Text(words[1]+","+words[8]));
				
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

            ArrayList<Text> tmp = new ArrayList<Text>();

            for (Text val : values) { 
                // Copie de val
                tmp.add(new Text(val));
                LOG.info(val.toString());
            }
            
            for (Text a : tmp) {
            	 String[] parts1=a.toString().split(",");
                for (Text b : tmp) {
                    // Votre traitement
                	String[] parts2=b.toString().split(",");
                	if(parts1[0].equals(parts2[0])) {
                		LOG.info(parts1[1]+"\t"+parts2[1]);
                		context.write(new Text(parts1[1]),new Text(parts2[1]));
                	}
                }
            }	
               
            

            
        }
    }
	

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Configuration conf = new Configuration();

		Job job = new Job(conf, "Reduce-side join");

		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);

		job.setJarByClass(Join.class);
		job.setReducerClass(Reduce.class);

		job.setOutputValueClass(Text.class); 

		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		MultipleInputs.addInputPath(job, new Path("input-join/customer.tbl.499"),TextInputFormat.class,CustomerMapper.class);
		MultipleInputs.addInputPath(job, new Path("input-join/orders.tbl.1"),TextInputFormat.class,OrderMapper.class);
		FileOutputFormat.setOutputPath(job, new Path(OUTPUT_PATH + Instant.now().getEpochSecond()));

		job.waitForCompletion(true);

	}

}
