#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

// 定义 eBPF Map，类型为哈希表
struct bpf_map_def SEC("maps") kv_db_map = {
    .type = BPF_MAP_TYPE_HASH,
    .key_size = sizeof(int),
    .value_size = sizeof(int),
    .max_entries = 1024, // 设置最大键值对数量
};

SEC("kern")
int kv_db_program(struct xdp_md *ctx) {
    return XDP_PASS;
}
