 /////////////////////////////////////
//          C O N T R O L L E R
// /////////////////////////////////////

class Controller {
  public:
    Controller (Show& lib, View& view) : show(lib), view(view) { }
    void cli();
    void execute_cmd(int cmd);
  private:
    int get_int(string prompt, int max_int);
    show& show;
    View& view;
};

void Controller::cli() {
  int cmd = -1;
  while (cmd != 0) {
    cout << view.get_menu() << endl;
    cout << "Command? ";
    cin >> cmd;
    cin.ignore(); // consume \n
    execute_cmd(cmd);
  }
}

int Controller::get_int(string prompt, int max_int) {
  int result;
  while(true) {
    cout << prompt;
    cin >> result;
    cin.ignore(); // consume \n
    if (0 <= result && result <= max_int) break;
    cout << "Please enter an integer between 0 and " << max_int << endl;
  }
  return result;
}

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { // Add publication
    string title, author, copyright, isbn;
    int genre, media, age;

    cout << "Title? ";
    getline(cin, title);

    cout << "Author? ";
    getline(cin, author);

    cout << "Copyright date? ";
    getline(cin, copyright);

    cout << view.get_genre_list();
    genre = get_int("Genre number? ", Genre::num_genres - 1);

    cout << view.get_media_list();
    media = get_int("Media number? ", Media::num_media - 1);

    cout << view.get_age_list();
    age = get_int("Age number? ", Age::num_ages - 1);

    cout << "ISBN? ";
    getline(cin, isbn);

    library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));

 } else if (cmd == 2) { // List all publications
    cout << view.get_publication_list();

 } else if (cmd == 3) { // Check out publication
    int pub, pat;

    cout << view.get_publication_list();
    pub = get_int("Publication number? ", library.number_of_publications() - 1);

    cout << view.get_patron_list();
    pat = get_int("Patron number? ", library.number_of_patrons() - 1);

    try {
      library.check_out(pub, pat);
    } catch (Publication::Invalid_transaction e) {
      cerr << "##### That publication is not available for check out" << endl;
    }

 } else if (cmd == 4) { // Check in publication
    int pub;
    cout << view.get_publication_list();
    pub = get_int("Publication number? ", library.number_of_publications() - 1);

    try {
      library.check_in(pub);
    } catch (Publication::Invalid_transaction e) {
       cerr << "##### That publication is not available for check in" << endl;
    }

 } else if (cmd == 5) { // Add patron
    string name, number;

    cout << "Name? ";
    getline(cin, name);
    cout << "Phone number? ";
    getline(cin, number);
    library.add_patron(Patron(name, number));

 } else if (cmd == 6) { // List all patrons
    cout << view.get_patron_list();

 } else if (cmd == 9) { // Help
    cout << view.get_help();
 } else if (cmd == 0) { // Exit
 } else if (cmd == 99) { // Easter Egg
   library.easter_egg();
 } else {
   cerr << "**** Invalid command - type 9 for help" << endl << endl;
 }
}
