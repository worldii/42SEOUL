find . -type f -name "*.sh" | xargs -I{} basename {} | rev | cut -c 4- | rev
