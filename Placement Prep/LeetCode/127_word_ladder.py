class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words_set = set(wordList)
        
        if endWord not in words_set:
            return 0
        q = collections.deque()
        
        trans = 0
        alpha_str = string.ascii_lowercase
        fin_lst = list(endWord)
        q.append(beginWord)
        while(len(q)>0):
            
            for i in range(len(q)):
                curr_word = q.popleft()
                if curr_word == endWord:
                    return trans+1

                for i in range(len(curr_word)):
                    lst = list(curr_word)
                    for ch in alpha_str:
                        lst[i] = ch
                        s = ''.join(lst)

                        if (s!=curr_word) and (s in words_set):
                            words_set.remove(s)
                            q.append(s)

            trans+=1
            
            
        return 0
