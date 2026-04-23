class TrieNode {
  constructor() {
    this.children = Array(26).fill(null);
    this.isEnd = false;
  }
}

class Trie {
  constructor() {
    this.root = new TrieNode();
  }

  insert(word) {
    let node = this.root;
    for (const ch of word) {
      const idx = ch.charCodeAt(0) - 97;
      if (!node.children[idx]) {
        node.children[idx] = new TrieNode();
      }
      node = node.children[idx];
    }
    node.isEnd = true;
  }

  search(word) {
    let node = this.root;
    for (const ch of word) {
      const idx = ch.charCodeAt(0) - 97;
      if (!node.children[idx]) {
        return false;
      }
      node = node.children[idx];
    }
    return node.isEnd;
  }
}

const trie = new Trie();
const insertedWords = new Set();

const wordInput = document.getElementById("wordInput");
const insertBtn = document.getElementById("insertBtn");
const searchBtn = document.getElementById("searchBtn");
const message = document.getElementById("message");
const wordList = document.getElementById("wordList");

function normalizeWord(rawValue) {
  return rawValue.trim().toLowerCase();
}

function isValidWord(word) {
  return /^[a-z]+$/.test(word);
}

function showMessage(text, type) {
  message.textContent = text;
  message.classList.remove("success", "warning");
  if (type) message.classList.add(type);
}

function renderWordList() {
  wordList.innerHTML = "";

  if (!insertedWords.size) {
    const empty = document.createElement("li");
    empty.textContent = "No words inserted yet.";
    wordList.appendChild(empty);
    return;
  }

  [...insertedWords]
    .sort((a, b) => a.localeCompare(b))
    .forEach((word) => {
      const li = document.createElement("li");
      li.textContent = word;
      wordList.appendChild(li);
    });
}

insertBtn.addEventListener("click", () => {
  const word = normalizeWord(wordInput.value);

  if (!word) {
    showMessage("Enter a word first.", "warning");
    return;
  }

  if (!isValidWord(word)) {
    showMessage("Only letters a-z are allowed.", "warning");
    return;
  }

  trie.insert(word);
  insertedWords.add(word);
  renderWordList();
  showMessage(`Inserted: ${word}`, "success");
  wordInput.focus();
  wordInput.select();
});

searchBtn.addEventListener("click", () => {
  const word = normalizeWord(wordInput.value);

  if (!word) {
    showMessage("Enter a word first.", "warning");
    return;
  }

  if (!isValidWord(word)) {
    showMessage("Only letters a-z are allowed.", "warning");
    return;
  }

  const found = trie.search(word);
  if (found) {
    showMessage(`Found in trie: ${word}`, "success");
  } else {
    showMessage(`Not found: ${word}`, "warning");
  }
});

wordInput.addEventListener("keydown", (event) => {
  if (event.key === "Enter") {
    insertBtn.click();
  }
});

renderWordList();
