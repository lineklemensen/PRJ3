-- counts words in a document

words = 0

wordcount = {
  Str = function(el)
    -- we don't count a word if it's entirely punctuation:
    if el.text:match("%P") then
        words = words + el.text:len("%P")
    end
  end,

  --Code = function(el)
  --  if el.text:match("%P") then
  --      words = words + el.text:len("%P")
  --  end
  --end,
--
  --CodeBlock = function(el)
  --  if el.text:match("%P") then
  --      words = words + el.text:len("%P")
  --  end
  --end
}

function Pandoc(el)
    -- skip metadata, just count body:
    el.blocks:walk(wordcount)
    print(words .. " characters in body")
    os.exit(0)
end