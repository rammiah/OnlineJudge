func reverseWords(s string) string {
	s = strings.TrimSpace(s)
	words := strings.Fields(s)
	// just reverse the slice
	for i, j := 0, len(words)-1; i < j; {
		words[i], words[j] = words[j], words[i]
		i++
		j--
	}

	return strings.Join(words, " ")
}
