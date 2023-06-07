#include <iostream>
#include <mecab.h>
#include <map>
#include <string>

// Mapping table for kana to romaji conversion
std::map<std::string, std::string> kanaToRomaji = {
    {"あ", "a"}, {"い", "i"}, {"う", "u"}, {"え", "e"}, {"お", "o"},
    // ... Add more kana characters and their corresponding romaji
    {"ア", "a"}, {"イ", "i"}, {"ウ", "u"}, {"エ", "e"}, {"オ", "o"},
    // ... Add more katakana characters and their corresponding romaji
};

std::string convertKanaToRomaji(const std::string& kana) {
    std::string romaji;
    MeCab::Tagger* tagger = MeCab::createTagger("");
    const MeCab::Node* node = tagger->parseToNode(kana.c_str());

    while (node) {
        if (node->length > 0) {
            std::string kanaChar(node->surface, node->surface + node->length);
            auto iter = kanaToRomaji.find(kanaChar);
            if (iter != kanaToRomaji.end()) {
                romaji += iter->second;
            }
        }
        node = node->next;
    }

    delete tagger;
    return romaji;
}

int main() {
    std::string kanaInput = "ひらがな カタカナ";
    std::string romajiOutput = convertKanaToRomaji(kanaInput);
    std::cout << romajiOutput << std::endl;

    return 0;
}
