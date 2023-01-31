use rand::Rng;

const SUITS: &[&str] = &["Clubs", "Spades", "Diamonds", "Hearts"];
const VALUES: &[&str] = &["2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"];


fn build_deck() -> Vec<String> {
    let mut deck = Vec::new();
    for suit in SUITS {
        for value in VALUES {
            deck.push(format!("{} of {}", value, suit));
        }
    }
    deck
}


fn output_deck(output_deck: &Vec<String>) {
    for card in output_deck {
        println!("{}", card);
    }
}

fn perfect_riffle_shuffle(deck: Vec<String>) -> Vec<String> {
    let mut shuffled_deck = Vec::new();
    let mid = deck.len() / 2;
    let mut left = deck[0..mid].to_vec();
    let mut right = deck[mid..deck.len()].to_vec();
    while left.len() > 0 || right.len() > 0 {
        if left.len() > 0 {
            shuffled_deck.push(left.remove(0));
        }
        if right.len() > 0 {
            shuffled_deck.push(right.remove(0));
        }
    }
    shuffled_deck
}

fn non_perfect_riffle_shuffle(deck: Vec<String>) -> Vec<String> {
    let mut rng = rand::thread_rng();
    let mut shuffled_deck = Vec::new();
    let mid = deck.len() / 2;
    let mut left = deck[0..mid].to_vec();
    let mut right = deck[mid..deck.len()].to_vec();
    while left.len() > 0 || right.len() > 0 {
        let take_from_left = rng.gen_bool(0.5);
        if take_from_left && left.len() > 0 {
            shuffled_deck.push(left.remove(0));
        } else if right.len() > 0 {
            shuffled_deck.push(right.remove(0));
        }
    }
    shuffled_deck
}

fn main() {
    let deck = build_deck();
    println!("Original deck:"); 
    output_deck(&deck);

    let perfect_shuffle = perfect_riffle_shuffle(deck.clone());
    println!("Perfect shuffle:");
    output_deck(&perfect_shuffle);

    let non_perfect_shuffle = non_perfect_riffle_shuffle(deck);
    println!("Non-perfect shuffle:");
    output_deck(&non_perfect_shuffle);
}
