/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package common;

import java.util.List;
import java.util.Set;

public interface IVertex<T> {
	
	boolean reachable(IVertex<T> v);
	
	void addLabel(ILabel<?> l);
	void removeLabel(ILabel<?> l);
	List<ILabel<?>> getLabels();
	
	void addEdge(IEdge<?> e);
	void removeEdge(IEdge<?> e);
	Set<IEdge<?>> getEdges();
	
	void setValue(VertexValue<T> v);
	VertexValue<T> getValue();
	
	boolean isMarked();
	void mark();
}
