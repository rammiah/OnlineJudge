func rankTeams(votes []string) string {
	if len(votes) == 1 {
		return votes[0]
	}
	type Player struct {
		Name  byte
		Votes [26]int
	}
	players := make([]*Player, 0, len(votes[0]))
	idxs := make(map[byte]int, 26)
	idx := 0

	// apply index
	for _, c := range []byte(votes[0]) {
		idxs[c] = idx
		players = append(players, &Player{
			Name: c,
		})
		idx++
	}

	// calcute votes
	for _, vote := range votes {
		for i, c := range []byte(vote) {
			players[idxs[c]].Votes[i]++
		}
	}

	sort.Slice(players, func(i, j int) bool {
		for idx := 0; idx < 26; idx++ {
			if players[i].Votes[idx] > players[j].Votes[idx] {
				return true
			} else if players[i].Votes[idx] < players[j].Votes[idx] {
				return false
			}
		}
		return players[i].Name < players[j].Name
	})

	var sb strings.Builder
	sb.Grow(len(players))

	for _, p := range players {
		sb.WriteByte(p.Name)
	}

	return sb.String()
}
