#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_
/**
 * Singleton template.
*/
template <typename C>
class Singleton {
	public:
		/**
		 * Get instance.
		*/
		static C* instance() {
			if (!_instance) {
				_instance = new C();
			};
			return _instance;
		}
		/**
		 * Destroy instance.
		*/
		virtual ~Singleton() {
			_instance = 0;
		}
	private:
		static C* _instance;
	protected:
		Singleton() { }
};
template <typename C> C* Singleton <C>::_instance = 0;
#endif
