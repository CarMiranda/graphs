/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package list;

import common.EdgeValue;
import common.IEdge;
import common.IVertex;

public class DirectedEdge<E> extends UndirectedEdge implements IEdge<E> {

	private final IVertex<?> tail; // From tail
	private final IVertex<?> head; // To head
	private EdgeValue<E> value;
	
	public DirectedEdge(IVertex<?> tail, IVertex<?> head) {
		this.tail = tail;
		this.head = head;
		this.value = new EdgeValue<E>();
	}

	public void setValue(EdgeValue<E> v) {
		this.value.setValue(v.getValue());
	}

	public EdgeValue<E> getValue() {
		return this.value;
	}
	
	public IVertex<?> getTail() {
		return tail;
	}
	
	public IVertex<?> getHead() {
		return head;
	}
	
}
