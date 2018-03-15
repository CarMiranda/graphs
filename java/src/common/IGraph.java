/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package common;

import java.util.Set;

public interface IGraph<V,E> {
	
	boolean adjacents(IVertex<V> v1, IVertex<V> v2);
	Set<IVertex<V>> neighbors(IVertex<V> v);
	
	void addVertex(IVertex<V> v);
	void removeVertex(IVertex<V> v);
	
	void addEdge(IVertex<V> v1, IVertex<V> v2, EdgeValue<E> e);
	void removeEdge(IVertex<V> v1, IVertex<V> v2);
	EdgeValue<E> getValue(IVertex<V> v1, IVertex<V> v2);
	void setValue(IVertex<V> v1, IVertex<V> v2, EdgeValue<E> val);

}
