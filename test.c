#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bpf/libbpf.h>

int main() {
    int map_fd;
    int key, value;

    // 获取已加载 eBPF Map 的文件描述符
    map_fd = bpf_obj_get("/sys/fs/bpf/dummy0/kv_db_map");

    // 插入键值对
    key = 1;
    value = 100;
    bpf_map_update_elem(map_fd, &key, &value, BPF_ANY);

    // 查询键值对
    key = 1;
    bpf_map_lookup_elem(map_fd, &key, &value);
    printf("Key: %d, Value: %d\n", key, value);

    return 0;
}
