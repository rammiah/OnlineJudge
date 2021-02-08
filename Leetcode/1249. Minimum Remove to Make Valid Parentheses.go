func minRemoveToMakeValid(s string) string {
    // lee(t(c)o)de)/lee(t(c)o)de
    // 栈操作
    var toDel []int
    var stack []int
    // 直接走起吧
    bs := []byte(s)
    for i, c := range bs {
        switch c {
        case '(':
            // 这个我要了
            stack = append(stack, i)
        case ')':
            // 看下栈里是不是空的
            if len(stack) > 0 {
                // stack踢出最后的一个
                stack = stack[:len(stack)-1]
            } else {
                toDel = append(toDel, i)
            }
        default:
            // donothing
        }
    }
    // 两个slice的对应的元素置空
    for _, i := range stack {
        bs[i] = ' '
    }
    for _, i := range toDel {
        bs[i] = ' '
    }

    return strings.ReplaceAll(string(bs), " ", "")
}
