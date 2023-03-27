# ebpf_map_kv_demo
编译 ebpf 程序命令：
```
clang -O2 -target bpf -c kv_db.c -o kv_db.o
```
加载 eBPF 程序：使用 ip 命令将编译好的 eBPF 程序加载到内核中。
```
sudo ip link set dev <网络接口名称例如 eth0 > xdp obj kv_db.o sec kern
```
这将把 kv_db.o 程序附加到 eth0 接口上。（使用虚拟机的情况下该接口可能不可用）

PS：
示例的 ebpf map 的文件描述符路径为：
```
map_fd = bpf_obj_get("/sys/fs/bpf/dummy0/kv_db_map");
```
请确保将 <map_path> 参数替换为您的 eBPF Map 的实际路径。
