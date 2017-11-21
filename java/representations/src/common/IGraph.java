/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package common;

import java.util.Set;

public interface IGraph<V,E> {
	
	boolean adjacent(IVertex<V> v1, IVertex<V> v2);
	Set<IVertex<V>> neighbors(IVertex<V> v);
	
	void addVertex(IVertex<V> v);
	void removeVertex(IVertex<V> v);
	VertexValue<V> getValue(IVertex<V> v);
	void setValue(IVertex<V> v, VertexValue<V> val);
	
	void addEdge(IEdge<E> e);
	void removeEdge(IEdge<E> e);
	EdgeValue<E> getValue(IEdge<E> e);
	void setValue(IEdge<E> e, EdgeValue<E> val);

}
