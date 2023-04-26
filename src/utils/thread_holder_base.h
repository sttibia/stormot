/**
 * Oliveira - A Private source MMORPG server emulator
 */

#ifndef SRC_UTILS_THREAD_HOLDER_H_
#define SRC_UTILS_THREAD_HOLDER_H_

#include "declarations.hpp"

template <typename Derived>
class ThreadHolder {
	public:
		ThreadHolder() { }
		void start() {
			setState(THREAD_STATE_RUNNING);
			thread = std::thread(&Derived::threadMain, static_cast<Derived*>(this));
		}

		void stop() {
			setState(THREAD_STATE_CLOSING);
		}

		void join() {
			if (thread.joinable()) {
				thread.join();
			}
		}

	protected:
		void setState(ThreadState newState) {
			threadState.store(newState, std::memory_order_relaxed);
		}

		ThreadState getState() const {
			return threadState.load(std::memory_order_relaxed);
		}

	private:
		std::atomic<ThreadState> threadState { THREAD_STATE_TERMINATED };
		std::thread thread;
};

#endif // SRC_UTILS_THREAD_HOLDER_H_
