/*
 * system.hpp
 *
 *  Created on: 04/08/18
 *      Author: hello@whatsthecraic.net
 */

#ifndef COMMON_SYSTEM_HPP
#define COMMON_SYSTEM_HPP

namespace common {


/**
 * Concurrency related settings
 */
namespace concurrency {

/**
 * Whether NUMA settings are available
 */
bool has_numa();

/**
 * Get the processor ID where the current thread is running
 */
int get_current_cpu();

/**
 * Get the Numa node associated to the CPU where the current thread is running
 */
int get_current_numa_node();

/**
 * Get the Numa node for the given CPU
 */
int get_numa_id(int cpu_id);

/**
 * Get the highest numa node in the system. Wrapper to `numa_max_node()'
 */
int get_numa_max_node();

/**
 * Pin the current thread to the current cpu and numa node. Optionally also pin the memory allocations from other NUMA nodes.
 */
void pin_thread_to_cpu(bool pin_numa_node = true);

/**
 * Pin the current thread to the given cpu and numa node. Disable memory allocations from the other NUMA nodes.
 * Note: as new created threads will inherit the same cpu mask, it is important to invoke this call to pin
 * an execution/sequential worker, rather than the main thread.
 */
void pin_thread_to_cpu(int cpu_id, bool pin_numa_node = true);

/**
 * Pin the current thread to the CPUs running at the given NUMA node
 */
void pin_thread_to_numa_node(int numa_node);

/**
 * Reset the pinning of the current thread
 * @param numa: if true, also unset the pinning to the NUMA node
 */
void unpin_thread(bool numa = true);


} // concurrency



} // common


#endif //COMMON_SYSTEM_HPP