namespace Lab_13
{
    partial class Form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.getButton = new System.Windows.Forms.Button();
            this.resetButton = new System.Windows.Forms.Button();
            this.quarters = new System.Windows.Forms.TextBox();
            this.tokens = new System.Windows.Forms.TextBox();
            this.quartersLabel = new System.Windows.Forms.Label();
            this.tokensLabel = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(248, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(52, 20);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // getButton
            // 
            this.getButton.Location = new System.Drawing.Point(90, 37);
            this.getButton.Name = "getButton";
            this.getButton.Size = new System.Drawing.Size(75, 23);
            this.getButton.TabIndex = 1;
            this.getButton.Text = "Get Token";
            this.getButton.UseVisualStyleBackColor = true;
            this.getButton.Click += new System.EventHandler(this.getButton_Click);
            // 
            // resetButton
            // 
            this.resetButton.Location = new System.Drawing.Point(90, 66);
            this.resetButton.Name = "resetButton";
            this.resetButton.Size = new System.Drawing.Size(75, 23);
            this.resetButton.TabIndex = 2;
            this.resetButton.Text = "Reset";
            this.resetButton.UseVisualStyleBackColor = true;
            this.resetButton.Click += new System.EventHandler(this.resetButton_Click);
            // 
            // quarters
            // 
            this.quarters.Location = new System.Drawing.Point(117, 108);
            this.quarters.Name = "quarters";
            this.quarters.ReadOnly = true;
            this.quarters.Size = new System.Drawing.Size(100, 20);
            this.quarters.TabIndex = 3;
            // 
            // tokens
            // 
            this.tokens.Location = new System.Drawing.Point(117, 140);
            this.tokens.Name = "tokens";
            this.tokens.ReadOnly = true;
            this.tokens.Size = new System.Drawing.Size(100, 20);
            this.tokens.TabIndex = 4;
            // 
            // quartersLabel
            // 
            this.quartersLabel.AutoSize = true;
            this.quartersLabel.Location = new System.Drawing.Point(12, 111);
            this.quartersLabel.Name = "quartersLabel";
            this.quartersLabel.Size = new System.Drawing.Size(99, 13);
            this.quartersLabel.TabIndex = 5;
            this.quartersLabel.Text = "Number of Quarters";
            // 
            // tokensLabel
            // 
            this.tokensLabel.AutoSize = true;
            this.tokensLabel.Location = new System.Drawing.Point(16, 143);
            this.tokensLabel.Name = "tokensLabel";
            this.tokensLabel.Size = new System.Drawing.Size(95, 13);
            this.tokensLabel.TabIndex = 6;
            this.tokensLabel.Text = "Number of Tokens";
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(248, 167);
            this.Controls.Add(this.tokensLabel);
            this.Controls.Add(this.quartersLabel);
            this.Controls.Add(this.tokens);
            this.Controls.Add(this.quarters);
            this.Controls.Add(this.resetButton);
            this.Controls.Add(this.getButton);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form";
            this.Text = "Token Machine";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.Button getButton;
        private System.Windows.Forms.Button resetButton;
        private System.Windows.Forms.TextBox quarters;
        private System.Windows.Forms.TextBox tokens;
        private System.Windows.Forms.Label quartersLabel;
        private System.Windows.Forms.Label tokensLabel;
    }
}

