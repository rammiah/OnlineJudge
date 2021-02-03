func distanceBetweenBusStops(distance []int, start int, destination int) int {
    if start == destination {
        return 0
    }
    // 计算两个结点之间的最短距离
    if start > destination {
        start, destination = destination, start
    }
    var asc, desc int
    n := len(distance)

    for i := 0; i < start; i++ {
        desc += distance[i]
    }
    for i := start; i < destination; i++ {
        asc += distance[i]
    }
    for i := destination; i < n; i++ {
        desc += distance[i]
    }

    if asc < desc {
        return asc
    }
    return desc
}
