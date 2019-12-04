package waterGame;
import java.util.Stack;

public class Invoker {
	Stack<ICommand> opStack;
	
	public Invoker() {
		opStack=new Stack<ICommand>();
	}
	
	public void doCommand(ICommand cmd) {
		cmd.execute();
	};
	
	public void undoLast() {
		ICommand cmd=opStack.pop();
		cmd.execute();
	};
}
