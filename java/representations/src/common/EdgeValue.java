/**
 * @author Carlos Miranda <carlos.miranda_lopez@insa-rouen.fr>
 *
 * @version 1.0.0
 * Nov 20, 2017
 */

package common;

public class EdgeValue<T extends Object> {
	
	private T value;
	
	// Constructors
	public EdgeValue() { this.value = null; }
	
	public EdgeValue(T v) { this.value = v; }
	
	// Getters and setters
	public T getValue() { return this.value; }
	public void setValue(T v) { this.value = v; }
}
