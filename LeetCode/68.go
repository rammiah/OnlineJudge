func fullJustify(words []string, maxWidth int) []string {
	var (
		result []string
		subs   = []string{}
		length = 0
	)

	for _, w := range words {
		if length+len(w)+len(subs) > maxWidth {
			result = append(result, buildLine(subs, length, maxWidth))
			subs = subs[:0]
			subs = append(subs, w)
			length = len(w)
		} else {
			subs = append(subs, w)
			length += len(w)
		}
	}
	var sb strings.Builder
	left := maxWidth - length
	for _, w := range subs {
		sb.WriteString(w)
		if left > 0 {
			sb.WriteByte(' ')
			left--
		}
	}
	sb.WriteString(strings.Repeat(" ", left))
	result = append(result, sb.String())

	return result
}

func buildLine(words []string, length, max int) string {
	N := len(words)
	if N == 1 {
		return words[0] + strings.Repeat(" ", max-length)
	}
	var sb strings.Builder
	avg := (max - length) / (N - 1)
	left := max - avg*(N-1) - length
	avgSpace := strings.Repeat(" ", avg)
	for _, w := range words[:N-1] {
		sb.WriteString(w)
		sb.WriteString(avgSpace)
		if left > 0 {
			sb.WriteByte(' ')
			left--
		}
	}
	sb.WriteString(words[N-1])

	return sb.String()
}
