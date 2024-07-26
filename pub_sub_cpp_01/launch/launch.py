import os
from launch import LaunchDescription
from launch_ros.actions import Node
from tracetools_launch.action import Trace

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='pub_sub_cpp_01',
            executable='publisher'
        ),
        Node(
            package='pub_sub_cpp_01',
            executable='subscriber'
        ),
        Trace(
            session_name='system',
            append_timestamp=True,
            base_path=os.path.dirname(os.path.realpath(__file__)),
            events_ust=[
                'ros2:*',
            ],
            events_kernel=[
                'sched_switch',
                'sched_waking',
                'sched_pi_setprio',
                'sched_process_fork',
                'sched_process_exit',
                'sched_process_free',
                'sched_wakeup',
                'irq_softirq_entry',
                'irq_softirq_raise',
                'irq_softirq_exit',
                'irq_handler_entry',
                'irq_handler_exit',
                'lttng_statedump_process_state',
                'lttng_statedump_start',
                'lttng_statedump_end',
                'lttng_statedump_network_interface',
                'lttng_statedump_block_device',
                'block_rq_complete',
                'block_rq_insert',
                'block_rq_issue',
                'block_bio_frontmerge',
                'sched_migrate',
                'sched_migrate_task',
                'power_cpu_frequency',
                'net_dev_queue',
                'netif_receive_skb',
                'net_if_receive_skb',
                'timer_hrtimer_start',
                'timer_hrtimer_cancel',
                'timer_hrtimer_expire_entry',
                'timer_hrtimer_expire_exit',
            ],
        ),
    ])