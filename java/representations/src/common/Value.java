/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package common;

public abstract class Value<T> {

	private T value;
	
	public Value(T v) {
		this.value = v;
	}
	
	public T getValue() {
		return this.value;
	}
	
	public void setValue(T v) {
		this.value = v;
	}
	
}
