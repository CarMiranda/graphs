/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package common;

public interface IEdge<T> {
	
	void setValue(EdgeValue<T> v);
	EdgeValue<T> getValue();
	
}
